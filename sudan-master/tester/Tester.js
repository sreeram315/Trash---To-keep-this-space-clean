import React, { Component } from 'react'
// // import logo from './logo.svg'
// import './App.css'
// import StudentList from './students/StudentList.js'

import TesterData from '../data/tester_data.json'

class TesterApp extends Component {
  constructor (props) {
    super(props)
    this.toggleCount = this.toggleCount.bind(this)
    this.state = {
    	count: 250,
    	doCount: false
    }
  }
  toggleCount (event) {
    event.preventDefault()
    this.setState({
    	doCount: !this.state.doCount
    })
  }
  render () {
  	const { count } = this.state
    return (
      <div>
        <button onClick={this.toggleCount}> start/stop count</button>
        <h1> {count}</h1>

      </div>

    )
  }

  componentDidMount () {
  	this.myInterval = setInterval(() => {
  		if (this.state.doCount) {
  			if (this.state.count === 0) {
  				console.log('timeup')
  				this.setState({
  					count: 'Time up',
  					doCount: false
  				})
  			} else {
	  		this.setState(prevState => ({
	  			count: prevState.count - 1
	  		}))
	  	}
  	}
  	}, 1)
  }
}

export default TesterApp
