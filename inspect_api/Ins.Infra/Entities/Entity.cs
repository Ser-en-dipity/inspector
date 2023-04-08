namespace Shaft.Infra.Entities;
public interface IEntity
{
	long Id { get; }

}

public class Entity : IEntity
{
	public long Id { get; set; }
}