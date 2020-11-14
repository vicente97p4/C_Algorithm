﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shoot_White : MonoBehaviour
{
    public Rigidbody rb;
    public float mult = 1;
    public bool turn = false;
    public int speed;
    float diffx, diffy;
    public Renderer rend;
    Shoot_Black shoot_black = GameObject.Find("Black0").GetComponent<Shoot_Black>();
    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
        rend.GetComponent<Renderer>();
    }

    // Update is called once per frame
    void Update()
    {
        
            Vector3 point = Camera.main.ScreenToWorldPoint(new Vector3(Input.mousePosition.x, Input.mousePosition.y, Input.mousePosition.z));
            Vector3 pos = this.gameObject.transform.position;
            diffx = pos[0] - point[0];
            diffy = pos[2] - point[2];
        if (turn)
        {
            if (Input.GetMouseButtonDown(0))
            {
                turn = false;
                rb.AddForce(diffx * mult, 0, diffy * mult, ForceMode.Impulse);
            }
        }
            if (pos[1] < -15)
            {
                transform.position = new Vector3(30, 16, 15);
                rb.velocity = Vector3.zero;
                rb.transform.rotation = Quaternion.Euler(0, 0, 0);
            }
            if (rb.velocity == Vector3.zero) { shoot_black.turn = true; }
        
    }
    private void OnMouseOver()
    {
        rend.material.color = Color.gray;
    }
    private void OnMouseExit()
    {
        rend.material.color = Color.black;
    }

}
