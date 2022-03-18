import React, { Component } from 'react'

import ReactMarkdown from 'react-markdown'

const input = '# This is a header\n\nAnd this is a paragraph'

class Markdown extends Component {
  render () {
  	const { input } = this.props
  	const disallowed = ['linkReference']
    return (
      <ReactMarkdown source={input} disallowedTypes={disallowed} />
    )
  }
}

export default Markdown
