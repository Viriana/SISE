using UnityEngine;
using System.Collections;

public class KnightScript : UnitScript {

	// Use this for initialization
	void Start () {
		life = 7;
		armor = 5;
		strength = 10;
		range = 1;
		movementSpeed = 1;
	}
	public void Attack(UnitScript Unit)
	{
		Destroy (Unit.gameObject);
		//Unit.life -= strength;
		//print (Unit.life);
	}

}
