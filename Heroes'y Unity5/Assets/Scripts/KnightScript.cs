using UnityEngine;
using System.Collections;

public class KnightScript : UnitScript {

	// Use this for initialization
	void Start () {
		life = 7;
		armor = 2;
		strength = 10;
		range = 1;
		movementSpeed = 1;
		Tag = Kind.simpleAttack;
		Vector3 tmpPos = this.transform.position;
		tmpPos.y += 0.25f;
		this.transform.position = tmpPos;
	}
	public override float UnitAction(UnitScript Unit)
	{
		if((Mathf.Abs(Unit.x - this.x) <=range) && (Mathf.Abs(Unit.y - this.y) <= range))
		{
			return strength * Random.Range(0.2f, 1);
		}
		return 0;
	}

}
