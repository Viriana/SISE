using UnityEngine;
using System.Collections;

public enum Kind {simpleAttack, areaAttack, heal};
public class UnitScript : MonoBehaviour {
	
	public int Player;
	public float life { get; set; }
	public bool isAlive = true;
	public float strength { get; set; }
	public int range { get; set; }
	public float armor {get; set;} 
	public int movementSpeed { get; set; }
	public int x { get; set; }
	public int y { get; set; }
	public Kind Tag { get; set; }
	public virtual float UnitAction(UnitScript Unit){return 0;	}

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
