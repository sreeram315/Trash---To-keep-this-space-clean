import React, { Component } from 'react'
import StudentData from '../data/students_list.json'

import StudentDetail from './StudentDetail'

class StudentList extends Component {
  constructor (props) {
    super(props)
    this.handleDataCallBack = this.handleDataCallBack.bind(this)
    this.handleDeleteStudentCallBack = this.handleDeleteStudentCallBack.bind(this)
    this.reverseOrder = this.reverseOrder.bind(this)
    this.sortByCGPA = this.sortByCGPA.bind(this)
    this.state = {
      StudentsDisplayed: null
    }
  }
  handleDataCallBack (newStudent) {
    let currentStudents = this.state.StudentsDisplayed
    // currentStudents.push(newStudent)
    let newStudents = currentStudents
    this.setState({
      StudentsDisplayed: newStudents
    })
  }

  handleDeleteStudentCallBack (student) {
    let currentStudents = this.state.StudentsDisplayed

    var index = currentStudents.indexOf(student) // find the index and remove that student
    if (index > -1) { currentStudents.splice(index, 1) }

    let newStudents = currentStudents
    this.setState({
      StudentsDisplayed: newStudents
    })
  }

  reverseOrder (event) {
    event.preventDefault()
    let newStudents = this.state.StudentsDisplayed
    this.setState({
      StudentsDisplayed: newStudents.reverse()
    })
  }

  sortByCGPA (event) {
    event.preventDefault()

    let newStudents = this.state.StudentsDisplayed
    // newStudents.sort((a, b) => a.reg_no < b.reg_no)
    newStudents.sort(function (a, b) {
      return b.cgpa - a.cgpa
    })
    console.log(newStudents)
    this.setState({
      StudentsDisplayed: newStudents
    })
  }

  componentDidMount () {
    this.setState({
      StudentsDisplayed: StudentData
    })
  }
  render () {
    let { StudentsDisplayed } = this.state
    return (
      <div>
        <button onClick={this.reverseOrder}>Reverse order</button>&ensp;
        <button onClick={this.sortByCGPA}>Sort by CGPA</button>
        { StudentsDisplayed !== null && StudentsDisplayed.length !== 0
          ? <div onClick={this.titleClicked}>
            <h1> Student List:  </h1>
            {StudentsDisplayed.map((item, index) => {
              return <StudentDetail
                student={item}
                key={`post-list-key ${index}`}
                dataCallBack={this.handleDataCallBack}
                deleteStudentCallBack={this.handleDeleteStudentCallBack} />
            })}
          </div>
          : <h1> No students to display </h1>}
      </div>
    )
  }
}

export default StudentList
