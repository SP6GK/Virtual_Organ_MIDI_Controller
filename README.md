# Virtual Organ MIDI Controller
This device scans switches on the organ console and sends MIDI commands to organ software to turn on or turn off ranks, effects, couplers etc.. It can also control swell pedals. <br>

This is a part of my DIY virtual theatre organ project that uses MidiTizer 260SP to imitate a real organ.<br> My controller was designed for a theatre organ but can be used for any kind of virtual organ. It sends MIDI control change commands with value specifying which stop should be pulled from the console.<br>
Visit my website to learn more about the whole project: <a href="https://sp6gk.com/organ_mb_tabs.html">Circuit board for controlling stops of virtual theatre organ</a> and <a href="https://sp6gk.com/diy_organ_console.html">Home made organ console</a>

<h3>Special thanks to "Code Thinker Hack" blog</h3>
They've made a code that controls simple keyboard, I have extended that solution to three shift registers and added more "keys". Link to the project on that blog : <a href="http://www.codetinkerhack.com/2012/11/how-to-turn-piano-toy-into-midi.html">How to turn Piano toy into MIDI keyboard (using Arduino/Atmega) </a><br>
Keys here are switches for your stops or ranks.

<h3>The Arduino code requires some libraries:</h3>
<ul>
  <li>MIDI      https://www.arduino.cc/reference/en/libraries/midi-library/</li>
  <li>HC595     https://www.arduino.cc/reference/en/libraries/shiftregister74hc595/</li>
</ul>


<h3>Stable version</h3>
The stops2713 is a tested version that implements only manual switching of ranks (also coupler, trems, sound effects etc..). This version works on my organ so you shouldn't have troubles with it. Swell is disabled by default, simply uncomment expression function in main loop if you want this device to controll swell pedals as well.

<h3>Development version</h3>
header files and stops_Pistons.ino are still in development and have not been tested! They implement general and division pistons so that controller can switch many stops after a press of one button. Header files are for configuration and can set your desired combinations. <br>
