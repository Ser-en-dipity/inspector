using Microsoft.EntityFrameworkCore;
using Shaft.Infra.Db;
using Shaft.Infra.Entities;

namespace Shaft.Infra.Services;

public interface IProductRepository
{
	IEnumerable<Product> Latest3 { get; }
	IEnumerable<Product> Today { get; }
	void AddProduct(Dictionary<string, double> specs, bool ok, string top_image_path, string bottom_image_path);

}

public class ProductRepository : IProductRepository
{
	private readonly ShaftDbContext _context;
	public ProductRepository(ShaftDbContext context)
	{
		_context = context;
	}
	public IEnumerable<Product> Latest3 => _context.Products.Count() < 3 ?
		new List<Product>() :
		_context.Products.OrderByDescending(p => p.Id).Take(3)
			.Include(x => x.Specs).ThenInclude(x => x.Meta).ToList();
	public IEnumerable<Product> Today
	{
		get
		{
			var today = DateTime.Today.ToUniversalTime();
			return _context.Products.Where(x => x.CreationTime > today)
				.Include(x => x.Specs).ThenInclude(x => x.Meta).ToList();
		}
	}
	public void AddProduct(Dictionary<string, double> specs, bool ok, string top_image_path, string bottom_image_path)
	{
		var product = new Product
		{
			Ok = ok,
			TopImagePath = top_image_path,
			BottomImagePath = bottom_image_path
		};

		foreach (var (spec_name, value) in specs)
		{
			var spec = new Spec
			{
				Product = product,
				Name = spec_name,
				Value = (decimal)value
			};
			product.Specs.Add(spec);
		}

		_context.Products.Add(product);

		_context.SaveChanges();
	}
}