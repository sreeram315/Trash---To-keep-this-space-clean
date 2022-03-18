import React from 'react'
import ReactDOM from 'react-dom'
import StudentInterface from './containers/students/StudentInterface'
// import App2 from './containers/App'

import '../scss/index.scss'

if (document.getElementById('react-app')) ReactDOM.render(<StudentInterface />, document.getElementById('react-app'))

if (document.getElementById('react-app2')) ReactDOM.render(<StudentInterface />, document.getElementById('react-app2'))

// ReactDOM.render(<App2 />, document.getElementById('react-app2'))
