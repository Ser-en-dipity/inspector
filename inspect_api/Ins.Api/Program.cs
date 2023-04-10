using Microsoft.EntityFrameworkCore;
using Shaft.Infra.Ros2;
using Shaft.Infra.Db;
using Shaft.Infra.Services;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

builder.Services.AddScoped<IProductRepository, ProductRepository>();

builder.Services.AddMemoryCache();
builder.Services.AddSingleton<Ros2Context>();
builder.Services.AddHostedService<LaunchAtStart>();
builder.Services.AddDbContext<ShaftDbContext>(options =>
{
    options.UseSqlite("Data Source=ins.db")
        .UseSnakeCaseNamingConvention();
});

var app = builder.Build();

using (var scope = app.Services.CreateScope())
{
    var ctx = scope.ServiceProvider.GetRequiredService<ShaftDbContext>();
    ctx.Database.EnsureCreated();
}

app.UseSwagger();
app.UseSwaggerUI();

app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();
