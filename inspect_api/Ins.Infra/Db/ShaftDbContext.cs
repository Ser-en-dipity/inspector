using Microsoft.EntityFrameworkCore;
using Shaft.Infra.Entities;

namespace Shaft.Infra.Db;

public class ShaftDbContext : DbContext
{
    public ShaftDbContext(DbContextOptions<ShaftDbContext> options) : base(options)
    {
    }
    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {

        modelBuilder.Entity<Product>()
            .HasKey(x => x.Id);
        modelBuilder.Entity<Product>()
            .HasIndex(x => x.ClientId);
        modelBuilder.Entity<Product>()
            .HasIndex(x => x.CreationTime);
        modelBuilder.Entity<Product>()
            .HasIndex(x => x.Ok);
        modelBuilder.Entity<Product>()
            .HasIndex(x => x.Desp);

        modelBuilder.Entity<Spec>()
            .HasKey(x => x.Id);
        modelBuilder.Entity<Spec>()
            .HasOne(s => s.Meta)
            .WithMany()
            .HasForeignKey(s => s.Name);
        modelBuilder.Entity<Spec>()
            .HasIndex(x => x.Ok);

        modelBuilder.Entity<SpecMeta>()
            .HasKey(x => x.Name);

        modelBuilder.Entity<SpecMeta>().HasData(
            new SpecMeta("chamfer", 1, 0.5m, 0),
            new SpecMeta("5_a", 12.038m, 12.012m, 12.026m),
            new SpecMeta("5_b", 12.038m, 12.012m, 12.026m),
            new SpecMeta("2", 92.1m, 91.2m, 91.9m)
        );

        base.OnModelCreating(modelBuilder);
    }

    public DbSet<Product> Products => Set<Product>();
    public DbSet<Spec> Specs => Set<Spec>();

}
