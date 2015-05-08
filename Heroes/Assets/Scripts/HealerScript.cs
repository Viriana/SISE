using UnityEngine;
using System.Collections;

public class HealerScript : UnitScript {

	// Use this for initialization
	void Start () {
		life = 7;
		armor = 5;
		strength = 4;
		range = 4;
		movementSpeed = 2;

		Vector3 tmpPos = this.transform.position;
		tmpPos.y += 0.25f;
		tmpPos.x += 0.15f;
		this.transform.position = tmpPos;
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
