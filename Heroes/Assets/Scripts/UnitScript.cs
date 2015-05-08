using UnityEngine;
using System.Collections;

public class UnitScript : MonoBehaviour {

	public int Player;
	public float life { get; set; }
	public bool isAlive = true;
	public int strength { get; set; }
	public int range { get; set; }
	public int armor {get; set;} 
	public int movementSpeed { get; set; }


	public void Attack(UnitScript Unit)
	{
	}

	// Use this for initialization

	void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		if(life <=0)
		{
			Destroy(this.gameObject);
		}
	}
}
