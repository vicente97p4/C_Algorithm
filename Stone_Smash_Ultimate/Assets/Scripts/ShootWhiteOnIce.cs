using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShootWhiteOnIce : MonoBehaviour
{
    AudioSource audioSource;
    public AudioSource audio;
    public AudioClip colsound;
    private Vector3 mOffset, startPos;
    private float mZCoord;
    public Rigidbody rb;
    public Renderer rend;
    public GameObject arrow,turnManager;
    public bool alive = true;
    public Turn turn;
    // Start is called before the first frame update
    void Start()
    {
        this.audio = this.gameObject.AddComponent<AudioSource>();
        this.audio.clip = this.colsound;
        this.audio.loop = false;
        rb = GetComponent<Rigidbody>();
        rend.GetComponent<Renderer>();
        turn = turnManager.GetComponent<Turn>();
        audioSource = GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 pos = this.gameObject.transform.position;
        if (pos[1] < -15)
        {
            audioSource.Play();
        }
        
        
        if (pos[1] < -15)
        {
            transform.position = new Vector3(-30, 11, -15);
            rb.velocity = Vector3.zero;
            rb.transform.rotation = Quaternion.Euler(0, 0, 0);
            alive = false;
        }
    }
    private void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.tag == "stone" && alive == true)
            this.audio.Play();
    }
    private void OnMouseDown()
    {
        if (turn.turnnum == 2 && alive == true)
        {
            mZCoord = Camera.main.WorldToScreenPoint(gameObject.transform.position).z;
            mOffset = gameObject.transform.position - GetMouseWorldPos();
            startPos = GetMouseWorldPos();
        }
    }
    private Vector3 GetMouseWorldPos()
    {
        Vector3 mousePoint = Input.mousePosition;
        mousePoint.z = mZCoord;
        return Camera.main.ScreenToWorldPoint(mousePoint);
    }
    private void OnMouseDrag()
    {
        if (turn.turnnum == 2 && alive == true)
        {
            float size = Mathf.Sqrt(Mathf.Pow(startPos.x - GetMouseWorldPos().x, 2) + Mathf.Pow(startPos.z - GetMouseWorldPos().z, 2));
            float angle = Mathf.Atan2(startPos.z - GetMouseWorldPos().z, startPos.x - GetMouseWorldPos().x) * 180 / Mathf.PI;
            arrow.transform.localScale = new Vector3(0.05f * size, 0.2f, 0.015f * size);
            arrow.transform.position = this.gameObject.transform.position;
            arrow.transform.rotation = Quaternion.Euler(0, -angle, 0);
        }
    }
    private void OnMouseUp()
    {
        if (turn.turnnum == 2 && alive == true)
        {
            rb.AddForce((startPos.x - GetMouseWorldPos().x)*2, 0, (startPos.z - GetMouseWorldPos().z)*2, ForceMode.Impulse);
            arrow.transform.rotation = Quaternion.Euler(0, 0, 0);
            arrow.transform.position = new Vector3(-10f, 0f, 0f);
            arrow.transform.localScale = new Vector3(1f, 0.2f, 0.3f);
            turn.turnnum = 3;
        }
    }
    private void OnMouseOver()
    {
        if (turn.turnnum == 2 && alive == true) { rend.material.color = Color.gray; }
        
    }
    private void OnMouseExit()
    {
        if (turn.turnnum == 2 && alive == true) { rend.material.color = Color.white; }
    }
}
