import React from 'react'
import cookie from 'react-cookies'

import StudentList from './StudentList'
import '../../../scss/index.scss'


class StudentInterface extends React.Component {
  constructor (props) {
    super(props)
    this.state = {
      students: []
    }
    this.loadData = this.loadData.bind(this);
  }

  // load data
  loadData =  () => {
    const thisComp = this
    console.log('requesting...')
    const endpoint = '/api/students/list/'
    let lookupOptions = {
      method: 'GET',
      headers: {
        'Content-Type': 'application/json'
      }
    }

    fetch(endpoint, lookupOptions)
      .then(function (response)  {
        return response.json()
      }).then(function (responseData) {
        console.log(responseData)
        thisComp.setState({
          students: responseData
        })
      }).catch(function (error) {
        console.log(error)
      })

     
  }

  // post data
  postData =  () => {
    console.log('requesting...')
    const endpoint = '/api/students/create/'
    const csrfToken = cookie.load('csrftoken')
    let data = {
        "reg_no": 8978567,
        "name": "Gadhar",
        "cgpa": 2,
        "section": "E1112",
        "course": "Few things!"
    }
    let lookupOptions = {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        'X-CSRFToken': csrfToken
      },
      body: JSON.stringify(data),
      credentials: 'include'
    }

    fetch(endpoint, lookupOptions)
      .then(function (response)  {
        return response.json()
      }).then(function (responseData) {
        console.log(responseData)
        const data = responseData

      }).catch(function (error) {
        console.log(error)
      })

      this.loadData()
  }

  // component did mount
  componentDidMount () {
    console.log('mounted')
    // this.postData()
  }

  // render
  render () {
    // const { data } = this.state
    const { students } = this.state
    let len = students.length
    console.log(students)
    console.log(students.length)
    return (
      <div>

        <button onClick={this.postData} className="btn btn-outline-primary"> Click here to add Gadhar to the list </button>
         <button onClick={this.loadData} className="btn btn-outline-primary marr"> Click here to load student data </button>

         <StudentList students={students}/>
           



       

      </div>
    )
  }
}

export default StudentInterface
