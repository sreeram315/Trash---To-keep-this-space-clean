import React, { Component } from 'react'

import { Link } from 'react-router-dom'

class DynamicRoutePage extends Component {
  componentDidMount () {
    const { slug } = this.props.match.params
  }

  render () {
    const { slug } = this.props.match.params
    return (
      <div>
        <h1> slug : {slug}</h1>
      </div>

    )
  }
}

export default DynamicRoutePage
