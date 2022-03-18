import React, { Component } from 'react'
import YouTube from 'react-youtube'

class YoutubeVideo extends Component {
  constructor (props) {
    super(props)
    this.state = {

    }
  }

  videoOnReady (event) {
    const player = event.target
    // player.seekTo(30.5)
    // player.pauseVideo()
  }

  videoOnPlay (event) {
    // const player = event.target
    // player.seekTo(100)
  }

  render () {
    const opts = {
      height: '390',
      width: '640',
      playerVars: { // https://developers.google.com/youtube/player_parameters
        autoplay: 0
      }
    }

    return (

      <YouTube
        videoId='jTTNWpag6fI'
        opts={opts}
        onReady={this.videoOnReady}
        onPlay={this.videoOnPlay}
      />
    )
  }
}

export default YoutubeVideo
