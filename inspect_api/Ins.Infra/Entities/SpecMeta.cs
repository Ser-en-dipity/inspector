namespace Shaft.Infra.Entities;

public class SpecMeta
{
    public const string metas = "metas";
    public SpecMeta(string name, decimal upper, decimal middle, decimal lower)
    {
        Name = name;
        Lower = lower;
        Middle = middle;
        Upper = upper;
    }
    // non-nullable property name
    public string Name { get; set; } = null!;
    public decimal Lower { get; set; }
    public decimal Upper { get; set; }
    public decimal Middle { get; set; }
    public string? Description { get; set; }

}
