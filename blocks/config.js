{
  module.exports = [
    {
      name: "Buzzer of T-Watch",
      blocks: [
        "music_setup",
        "music_note",
        {
          xml:
            `<block type="music_play_notes">
                        <value name="note">                    
                            <block type="music_notes">
                                <field name="notes">C4,B4,E4</field>
                            </block>
                        </value>
                    </block>`
        },
        "music_notes",
        "music_song_mario_underworld",
        "music_song_jingle_bell",
        "music_song_cannon_rock"
      ]
    }
  ];
}
