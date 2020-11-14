using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Turn : MonoBehaviour
{
    public int turnnum = 0;
    public GameObject B0,B1,B2,B3,B4,W0,W1,W2,W3,W4,bs,ws,win;
    public Rigidbody[] rbb,rbw;
    public Shoot_Black[] scb;
    public Shoot_White[] scw;
    public Text bsc, wsc, winner;
    // Start is called before the first frame update
    void Start()
    {
        bsc = bs.GetComponent<Text>();
        wsc = ws.GetComponent<Text>();
        winner = win.GetComponent<Text>();
        rbb = new Rigidbody[5];
        rbw = new Rigidbody[5];
        scb = new Shoot_Black[5];
        scw = new Shoot_White[5];
        rbb[0] = B0.GetComponent<Rigidbody>();
        rbb[1] = B1.GetComponent<Rigidbody>();
        rbb[2] = B2.GetComponent<Rigidbody>();
        rbb[3] = B3.GetComponent<Rigidbody>();
        rbb[4] = B4.GetComponent<Rigidbody>();
        rbw[0] = W0.GetComponent<Rigidbody>();
        rbw[1] = W1.GetComponent<Rigidbody>();
        rbw[2] = W2.GetComponent<Rigidbody>();
        rbw[3] = W3.GetComponent<Rigidbody>();
        rbw[4] = W4.GetComponent<Rigidbody>();
        scb[0] = B0.GetComponent<Shoot_Black>();
        scb[1] = B1.GetComponent<Shoot_Black>();
        scb[2] = B2.GetComponent<Shoot_Black>();
        scb[3] = B3.GetComponent<Shoot_Black>();
        scb[4] = B4.GetComponent<Shoot_Black>();
        scw[0] = W0.GetComponent<Shoot_White>();
        scw[1] = W1.GetComponent<Shoot_White>();
        scw[2] = W2.GetComponent<Shoot_White>();
        scw[3] = W3.GetComponent<Shoot_White>();
        scw[4] = W4.GetComponent<Shoot_White>();
        for(int i = 0; i < 5; i++)
        {
            rbb[i].velocity = Vector3.zero;
            rbw[i].velocity = Vector3.zero;
            rbb[i].rotation = Quaternion.Euler(new Vector3(0,0,0));
            rbw[i].rotation = Quaternion.Euler(new Vector3(0, 0, 0));
            scb[i].alive = true;
            scw[i].alive = true;
        }
        rbb[0].position = new Vector3(-12.5f, 1f, 13f);
        rbb[1].position = new Vector3(-6f, 1f, 6.5f);
        rbb[2].position = new Vector3(-12.5f, 1f, 0f);
        rbb[3].position = new Vector3(-6f, 1f, -6.5f);
        rbb[4].position = new Vector3(-12.5f, 1f, -13f);
        rbw[0].position = new Vector3(12.5f, 1f, -13f);
        rbw[1].position = new Vector3(6f, 1f, -6.5f);
        rbw[2].position = new Vector3(12.5f, 1f, 0f);
        rbw[3].position = new Vector3(6f, 1f, 6.5f);
        rbw[4].position = new Vector3(12.5f, 1f, 13f);
        turnnum = 0;
        win.transform.position = new Vector3(Screen.width / 2, Screen.height + 500, 0);
    }

    // Update is called once per frame
    void Update()
    {
        StartCoroutine(Wait());
    }
    IEnumerator Wait()
    {
        if (turnnum == 1||turnnum==3) yield return new WaitForSecondsRealtime(0.001f);
        int j = 0,bd=0,wd=0;
        for(int i = 0; i < 5; i++)
        {
            if (rbb[i].velocity == Vector3.zero || scb[i].alive == false) j++;
            if (rbw[i].velocity == Vector3.zero || scw[i].alive == false) j++;
            if (scb[i].alive == false) bd++;
            if (scw[i].alive == false) wd++;
        }
        if (turnnum == 0 || turnnum == 2)
        {
            if (bd == 5 && wd == 5)
            {
                Debug.Log("Draw");
                winner.text = "Draw";
                winner.color = Color.grey;
                win.transform.position = new Vector3(Screen.width / 2, Screen.height / 2, 0);
            }
            else if (bd == 5)
            {
                Debug.Log("White Wins");
                winner.text = "White Wins!";
                winner.color = Color.white;
                win.transform.position = new Vector3(Screen.width / 2, Screen.height / 2, 0);
            }
            else if (wd == 5)
            {
                Debug.Log("Black Wins");
                winner.text = "Black Wins!";
                winner.color = Color.black;
                win.transform.position = new Vector3(Screen.width / 2, Screen.height / 2, 0);
            }
        }
        if (j == 10)
        {
            if (turnnum == 1)
            {
                turnnum = 2;
            }
            if (turnnum == 3)
            {
                turnnum = 0;
            }
        }
        j = 0;
        bsc.text = (5 - bd).ToString();
        wsc.text = (5 - wd).ToString();
    }
}
