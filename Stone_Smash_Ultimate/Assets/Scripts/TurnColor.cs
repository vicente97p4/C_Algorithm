using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TurnColor : MonoBehaviour
{
    public GameObject manager;
    public Turn turn;
    public Renderer rend;
    // Start is called before the first frame update
    void Start()
    {
        turn = manager.GetComponent<Turn>();
        rend = GetComponent<Renderer>();
    }

    // Update is called once per frame
    void Update()
    {
        if (turn.turnnum == 0 || turn.turnnum == 1) { rend.material.color = Color.black; }
        if (turn.turnnum == 2 || turn.turnnum == 3) { rend.material.color = Color.white; }
    }
}
