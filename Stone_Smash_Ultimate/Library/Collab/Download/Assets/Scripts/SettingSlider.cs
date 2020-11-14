using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SettingSlider : MonoBehaviour
{
    public Slider backVolume;
    public AudioSource audio;

    private float backVol = 1f;
    void Start()
    {
        backVol = PlayerPrefs.GetFloat("backvol", 1f);
        backVolume.value = backVol;
        audio.volume = backVolume.value;
    }
    // Start is called before the first frame update
    

    // Update is called once per frame
    
    public void SoundSlider()
    {
        audio.volume = backVolume.value;

        backVol = backVolume.value;
        PlayerPrefs.SetFloat("backvol", backvol);
    }
    void Update()
    {
        SoundSlider;
    }
}
