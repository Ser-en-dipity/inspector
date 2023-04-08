using Microsoft.AspNetCore.Mvc;

namespace Ins.Api.Controllers;

[ApiController]
[Route("[controller]")]
public class InspectorController : ControllerBase
{
    private readonly ILogger<InspectorController> _logger;

    public InspectorController(ILogger<InspectorController> logger)
    {
        _logger = logger;
    }

    [HttpGet()]
    public void Get()
    {

    }
}
