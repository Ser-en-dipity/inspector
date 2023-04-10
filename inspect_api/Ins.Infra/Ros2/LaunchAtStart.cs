using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;

namespace Shaft.Infra.Ros2;

public class LaunchAtStart : IHostedService
{
	private readonly ILogger<LaunchAtStart> _logger;
	private readonly Ros2Context _ros2Context;

	public LaunchAtStart(ILogger<LaunchAtStart> logger, Ros2Context ros2Context)
	{
		_logger = logger;
		_ros2Context = ros2Context;
	}

	public Task StartAsync(CancellationToken cancellationToken)
	{
		_logger.LogInformation("Starting ros2 context");
		_ros2Context.Activate();
		return Task.CompletedTask;
	}

	public Task StopAsync(CancellationToken cancellationToken)
	{
		_ros2Context.Deactivate();
		return Task.CompletedTask;
	}
}
