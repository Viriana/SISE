using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class CentralScript : MonoBehaviour {
	//static public bool[,] Fields = new bool[15,11];
	static public List<FieldScript> Fields = new List<FieldScript>();
	static public bool somethingSelected = false;
	static public FieldScript SelectedField = null;
	private bool tmp = true;
	static public int Round {get; set;}

	void Start () {
		Round = 1;
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
		print (Round);
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
	static public void ChangeRound()
	{
		if(Round == 1)
		{
			Round = 2;
		}else if( Round == 2)
		{
			Round = 1;
		}
	}
	static public void ClickField(int x, int y)
	{
		if(somethingSelected)
		{
			FieldScript tmpField = FindField(x, y);
			UnitScript  of = SelectedField.InstHero.GetComponent<UnitScript>();
			if(of.Player != Round)
			{
				print("round: " + Round + "player: " + of.Player);
				return;
			}
			if(tmpField.hero != null)
			{
				UnitScript def = tmpField.InstHero.GetComponent<UnitScript>();
				if(of.Tag == Kind.simpleAttack)
				{
					if(of.Player != def.Player)
					{
						float finallyAttack = of.UnitAction(def) - def.armor;
						if(finallyAttack > 0)
							def.life -= finallyAttack;
					}
				}else if(of.Tag == Kind.heal)
				{
					if(of.Player == def.Player)
					{
						def.life += of.UnitAction(def);
					}
				}else if(of.Tag == Kind.areaAttack)
				{
					List<FieldScript> tmpFields = new List<FieldScript>();
					int tmpX = def.x;
					int tmpY = def.y;
					tmpFields.Add(tmpField);
					if(((float)tmpY%2) != 0)
					{
						FieldScript f1 = new FieldScript();
						f1.x = tmpX--;
						f1.y = tmpY--;
						tmpFields.Add(f1);
						FieldScript f2 = new FieldScript();
						f2.x = tmpX;
						f2.y = tmpY--;
						tmpFields.Add(f2);
						FieldScript f3 = new FieldScript();
						f3.x = tmpX++;
						f3.y = tmpY;
						tmpFields.Add(f3);
						FieldScript f4 = new FieldScript();
						f4.x = tmpX;
						f4.y = tmpY++;
						tmpFields.Add(f4);
						FieldScript f5 = new FieldScript();
						f5.x = tmpX--;
						f5.y = tmpY++;
						tmpFields.Add(f5);
						FieldScript f6 = new FieldScript();
						f6.x = tmpX--;
						f6.y = tmpY;
						tmpFields.Add(f6);
					}else
					{
						FieldScript f1 = new FieldScript();
						f1.x = tmpX;
						f1.y = tmpY--;
						tmpFields.Add(f1);
						FieldScript f2 = new FieldScript();
						f2.x = tmpX++;
						f2.y = tmpY--;
						tmpFields.Add(f2);
						FieldScript f3 = new FieldScript();
						f3.x = tmpX--;
						f3.y = tmpY;
						tmpFields.Add(f3);
						FieldScript f4 = new FieldScript();
						f4.x = tmpX++;
						f4.y = tmpY++;
						tmpFields.Add(f4);
						FieldScript f5 = new FieldScript();
						f5.x = tmpX;
						f5.y = tmpY++;
						tmpFields.Add(f5);
						FieldScript f6 = new FieldScript();
						f6.x = tmpX--;
						f6.y = tmpY;
						tmpFields.Add(f6);
					}
					foreach(var elem in tmpFields)
					{
						FieldScript tmpField2 = FindField(elem.x, elem.y);
						if(tmpField2.hero != null)
						{
							UnitScript def2 = tmpField2.InstHero.GetComponent<UnitScript>();
							float finallyAttack = of.UnitAction(def2) - def2.armor;
							if(finallyAttack > 0)
								def2.life -= finallyAttack;
						}
					}
				}
				SelectedField = null;
				somethingSelected = false;
				ChangeRound();
				print(def.life);
			}else
			{

				if((Mathf.Abs(tmpField.x - of.x)<= of.movementSpeed) && (Mathf.Abs(tmpField.y - of.y)<= of.movementSpeed))
				{
					tmpField.hero = SelectedField.hero;
					SaveHero(tmpField);
					Destroy( SelectedField.InstHero);
					SelectedField = null;
					somethingSelected = false;
					ChangeRound();
				}
			}

		}else
		{
			FieldScript tmpField =  FindField(x, y);
			UnitScript  of = tmpField.InstHero.GetComponent<UnitScript>();
			if(of.Player != Round)
			{
				print("round: " + Round + "player: " + of.Player);
				return;
			}
			SelectedField = tmpField;
			somethingSelected = true;
			//print(somethingSelected);
		}
	}
}
