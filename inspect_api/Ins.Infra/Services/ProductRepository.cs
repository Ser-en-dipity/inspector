using Microsoft.EntityFrameworkCore;
using Shaft.Infra.Db;
using Shaft.Infra.Entities;

namespace Shaft.Infra.Services;

public interface IProductRepository
{
    IEnumerable<Product> Latest3 { get; }
    IEnumerable<Product> Today { get; }
    void AddProduct(int clientId, bool ok, string desp);

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
    public void AddProduct(int clientId, bool ok, string desp)
    {
        var product = new Product
        {
            Ok = ok,
            Desp = desp,
            ClientId = clientId
        };

        _context.Products.Add(product);

        _context.SaveChanges();
    }
}