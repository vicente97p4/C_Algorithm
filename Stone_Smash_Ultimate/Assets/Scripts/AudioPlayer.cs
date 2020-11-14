using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioPlayer : MonoBehaviour
{
    private AudioSource musicPlayer;
    public AudioClip backgroundMusic;
    public static void playSound(AudioClip clip, AudioSource audioPlayer)
    {
        audioPlayer.Stop();
        audioPlayer.clip = clip;
        audioPlayer.loop = true;
        audioPlayer.time = 0;
        audioPlayer.Play();
    }
    void Start()
    {
        musicPlayer = GetComponent<AudioSource>();
        playSound(backgroundMusic, musicPlayer);
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
