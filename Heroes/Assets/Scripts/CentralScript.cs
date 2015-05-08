using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class CentralScript : MonoBehaviour {
	//static public bool[,] Fields = new bool[15,11];
	static public List<FieldScript> Fields = new List<FieldScript>();
	static public bool somethingSelected = false;
	static public FieldScript SelectedField = null;
	private bool tmp = true;
	void Start () {

	}

	void Update () {
		if(tmp)
		{
			foreach(var element in Fields)
			{
				print(element.x + " " + element.y);
			}
			tmp = false;
		}
	}

	static public FieldScript FindField(int x, int y)
	{
		foreach(var element in Fields)
		{
			if((element.x == x) && (element.y == y))
			{
				return element;
			}
		}
		return null;
	}
	static public void SaveHero(FieldScript _field)
	{
		foreach(var element in Fields)
		{
			if((element.x == _field.x) && (element.y == _field.y))
			{
				element.hero = _field.hero;
				element.CreateHero();
			}
		}
	}
	static public void ClickField(int x, int y)
	{
		if(somethingSelected)
		{
			FieldScript tmpField = FindField(x, y);
			if(tmpField.hero != null)
			{
				UnitScript def = tmpField.InstHero.GetComponent<UnitScript>();
				UnitScript  of = SelectedField.InstHero.GetComponent<UnitScript>();
				def.life -= 10;
				//Destroy(def.gameObject);
				//of.Attack(def);
				print(def.life);
			}else
			{
				tmpField.hero = SelectedField.hero;
				SaveHero(tmpField);
				//SelectedField.hero = null;
				//SaveHero(SelectedField);
				Destroy( SelectedField.InstHero);
			}
			SelectedField = null;
			somethingSelected = false;
		}else
		{
			SelectedField =  FindField(x, y);
			somethingSelected = true;
			//print(somethingSelected);
		}
	}
}
