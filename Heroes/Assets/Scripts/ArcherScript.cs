using UnityEngine;
using System.Collections;

public class ArcherScript : UnitScript {

	// Use this for initialization
	void Start () {
		life = 3;
		armor = 1;
		strength = 3;
		range = 4;
		movementSpeed = 2;
		Tag = Kind.simpleAttack;
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
