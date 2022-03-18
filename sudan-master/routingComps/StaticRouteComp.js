import React, { Component } from 'react'

import { Link } from 'react-router-dom'

class AboutPage extends Component {
  render () {
    return (
      <div>
        <h1> This page is ABOUT YOU</h1>
        <Link className='students-link' to='/students' >Students</Link>
      </div>

    )
  }
}

export default AboutPage
