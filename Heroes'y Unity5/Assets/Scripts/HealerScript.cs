using UnityEngine;
using System.Collections;

public class HealerScript : UnitScript {

	// Use this for initialization
	void Start () {
		life = 7;
		armor = 1;
		strength = 4;
		range = 4;
		movementSpeed = 2;
		Tag = Kind.heal;
		Vector3 tmpPos = this.transform.position;
		tmpPos.y += 0.25f;
		this.transform.position = tmpPos;
	}

	public override float UnitAction(UnitScript Unit)
	{
		if(((Unit.x - this.x) <=range) && ((Unit.y - this.y) <= range))
		{
			return strength * Random.Range(0.1f, 1);;
		}
		return 0;
	}
}
