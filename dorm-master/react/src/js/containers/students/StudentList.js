import React from 'react'
import cookie from 'react-cookies'

import '../../../scss/index.scss'
import './css/css.css'

import StudentAsRow from './StudentAsRow'

class StudentList extends React.Component {
  constructor (props) {
    super(props)
  }

  render () {
  	const { students } = this.props
    return (
      <div>
        <div className='headline lead'> Student List</div>
        {students.length > 0 ? students.map((stu, index) => {
        	return (
            <div>
            <StudentAsRow student={stu} />
          </div>
        	)
        })
          : 'No posts to display'
        }
      </div>
    )
  }
}

export default StudentList
