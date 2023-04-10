namespace Shaft.Infra.Entities;

public class Product : Entity
{
    public ISet<Spec> Specs { get; set; } = new HashSet<Spec>();
    public int ClientId { get; set; }
    public DateTime CreationTime { get; set; } = DateTime.Now;
    public bool Ok { get; set; }
    public string Desp { get; set; }
}
public static class ProductHelper
{
    public static double Length(this Product product) => (double)product.Specs.Single(x => x.Name == "2").Value;
    public static double OuterDiameterA(this Product product) => (double)product.Specs.Single(x => x.Name == "5_a").Value;
    public static double OuterDiameterB(this Product product) => (double)product.Specs.Single(x => x.Name == "5_b").Value;
    // public static bool LeftChamfer(this Product product) => product.Specs.Single(x => x.Name == "left_chamfer").Ok;
    // public static bool RightChamfer(this Product product) => product.Specs.Single(x => x.Name == "right_chamfer").Ok;
    public static bool Chamfer(this Product product) => product.Specs.Single(x => x.Name == "chamfer").Ok;

    public static bool IsOk(this Product product) => product.Specs.All(x => x.Ok);
    public static int CountOk(this IEnumerable<Product> products) => products.Count(x => x.Ok);
    public static int CountFail(this IEnumerable<Product> products) => products.Count(x => !x.Ok);
    public static int LengthFail(this IEnumerable<Product> products) => products.Count(x => !x.Specs.Single(x => x.Name == "2").Ok);
    public static int OuterDiameterAFail(this IEnumerable<Product> products) => products.Count(x => !x.Specs.Single(x => x.Name == "5_a").Ok);
    public static int OuterDiameterBFail(this IEnumerable<Product> products) => products.Count(x => !x.Specs.Single(x => x.Name == "5_b").Ok);
    // public static int LeftChamferFail(this IEnumerable<Product> products) => products.Count(x => !x.Specs.Single(x => x.Name == "chamfer").Ok);
    // public static int RightChamferFail(this IEnumerable<Product> products) => products.Count(x => !x.Specs.Single(x => x.Name == "right_chamfer").Ok);
    public static int ChamferFail(this IEnumerable<Product> products) => products.Count(x => !x.Specs.Single(x => x.Name == "chamfer").Ok);

}