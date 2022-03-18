import React, { Component } from 'react'

// third party
import { BrowserRouter, Route, Switch, Redirect } from 'react-router-dom'
import { Link } from 'react-router-dom'
// import logo from './logo.svg'
import './App.css'
import StudentList from './students/StudentList.js'
import StudentForm from './students/StudentForm.js'

import YoutubeVideo from './third_party/video.js'
import Markdown from './third_party/markdown.js'
import TesterApp from './tester/Tester.js'
import TesterApp2 from './tester/Tester2.js'
import TesterApp3 from './tester/Tester3.js'
// Routers
import DynamicRoutePage from './routingComps/DynamicRouteComp'
import AboutPage from './routingComps/StaticRouteComp'
import NotFoundPage from './routingComps/NotFoundRouteComp'

class App extends Component {
  render () {
    // const input = '# This is a header\n\n***And this is a paragraph***'
    return (
      <div className='App' >
        <TesterApp3 />
      </div>
    )

    // const loggedIn = true
    // const supportsHistory = 'pushState' in window.history
    // return (
    //   <div className='App' >
    //     <nav className='navbar'>
    //       <a className='navbar-one' href='/'>Home</a>&ensp;
    //       <a className='navbar-about' href='/about'>About</a>&ensp;
    //       <a className='navbar-students' href='/students'>Student Page</a>&ensp;
    //       <a className='navbar-video' href='/video'>Video</a>
    //     </nav>
    //     <BrowserRouter forceRefreah={!supportsHistory}>
    //       <Switch>
    //         <Route exact path='/about' component={AboutPage} />
    //         <Route path='/students/:slug' component={DynamicRoutePage} />
    //         <Route path='/students' component={StudentList} />
    //         <Route path='/video' component={YoutubeVideo} />
    //         <Route component={NotFoundPage} />
    //       </Switch>
    //     </BrowserRouter>
    //   </div>

    // )
  }
}

export default App
