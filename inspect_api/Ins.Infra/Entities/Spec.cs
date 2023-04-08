namespace Shaft.Infra.Entities;

public class Spec : Entity
{
	public string Name { get; set; } = null!;
	public virtual SpecMeta Meta { get; set; } = null!;
	public long ProductId { get; set; }
	public virtual Product Product { get; set; } = null!;
	public decimal Value { get; set; }
	public DateTime CreationTime { get; set; } = DateTime.Now;
	public bool Ok { get; set; }

}