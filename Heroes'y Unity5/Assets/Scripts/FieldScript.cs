using UnityEngine;
using System.Collections;

public class FieldScript : MonoBehaviour {

	public int x;
	public int y;
	public GameObject hero;
	public GameObject InstHero = null;
	// Use this for initialization
	void Start () {
		if(hero != null)
		{
			CreateHero();
		}
		CentralScript.Fields.Add (this);
	}
	public void CreateHero()
	{

		Vector3 tmpPos = this.transform.position;
		//tmpPos.x -= 0.2f;
		InstHero = (GameObject)Instantiate(hero, tmpPos, hero.gameObject.transform.rotation);
		UnitScript Usc = InstHero.GetComponent<UnitScript> ();
		Usc.x = x;
		Usc.y = y;
	}
	// Update is called once per frame
	void Update () {

	}

	public void OnMouseDown(){
		if((hero != null) || CentralScript.somethingSelected)
		{
			CentralScript.ClickField(x, y);
			//Destroy(InstHero);
			//hero = null;
		}
	}   

}
