using Microsoft.AspNetCore.Mvc;
using Shaft.Infra.Services;

namespace Ins.Api.Controllers;

[ApiController]
[Route("[controller]")]
public class InspectorController : ControllerBase
{
    private readonly ILogger<InspectorController> _logger;
    private readonly IProductRepository _productRepository;

    public InspectorController(ILogger<InspectorController> logger,
                        IProductRepository productRepository)
    {
        _logger = logger;
        _productRepository = productRepository;
    }

    [HttpGet("statistics")]
    [Produces("application/json")]
    public ActionResult<IEnumerable<ProductRepository>> Get()
    {
        var products = _productRepository.Today.ToList();
        return Ok(products);
    }
}
