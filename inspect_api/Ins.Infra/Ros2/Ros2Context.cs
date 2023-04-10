using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Logging;
using Rcl;
using Shaft.Infra.Services;
using Ins_ros2.Ins;
using System;

namespace Shaft.Infra.Ros2;

public class Ros2Context : IDisposable
{
    private readonly ILogger<Ros2Context> _logger;
    private readonly RclContext _rclContext;
    private readonly IRclNode _node;
    private IServiceProvider Services { get; }

    public Ros2Context(ILogger<Ros2Context> logger, IServiceProvider services, IConfiguration configuration)
    {
        _logger = logger;
        _rclContext = new RclContext();
        _node = _rclContext.CreateNode("subscriber");
        Services = services;
    }
    public async Task GetMessages()
    {
        _logger.LogInformation("start hosted service");
        IRclSubscription<Ins_ros2.Ins.Product> ins_sub = _node.CreateSubscription<Product>(
        "/topic");
        IAsyncEnumerable<Ins_ros2.Ins.Product> msgs = ins_sub.ReadAllAsync();
        _logger.LogInformation(msgs.ToString());
        await foreach (Ins_ros2.Ins.Product msg in msgs)
        {
            _logger.LogInformation("exec ::" + msg.ClientId + msg.Name);
        }
    }
    public void Activate()
    {
        GetMessages();
        using var scope = Services.CreateScope();
        var product_repo = scope.ServiceProvider.GetRequiredService<IProductRepository>();
        product_repo.AddProduct(1, true, "this is test");
    }
    public void Deactivate()
    {

    }
    private bool disposed = false;

    private void Dispose(bool disposing)
    {
        if (!disposed)
        {
            if (disposing)
            {
                // called via myClass.Dispose(). 
                // OK to use any private object references
                _node.Dispose();
                _rclContext.Dispose();
            }
            // Release unmanaged resources.
            // Set large fields to null.                
            disposed = true;
        }
    }


    public void Dispose()
    {
        Dispose(true);
        GC.SuppressFinalize(this);
    }
    ~Ros2Context()
    {
        Dispose(false);
    }
}
