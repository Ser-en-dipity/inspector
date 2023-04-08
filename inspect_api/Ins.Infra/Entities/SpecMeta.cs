namespace Shaft.Infra.Entities;

public class SpecMeta
{
	public const string metas = "metas";
	public SpecMeta(string name, decimal upper, decimal lower)
	{
		Name = name;
		Lower = lower;
		Upper = upper;
	}
	// non-nullable property name
	public string Name { get; set; } = null!;
	public decimal Lower { get; set; }
	public decimal Upper { get; set; }
	public string? Description { get; set; }

}
