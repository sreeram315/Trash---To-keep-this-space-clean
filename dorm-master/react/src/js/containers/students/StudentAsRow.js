import React from 'react'
import cookie from 'react-cookies'

class StudentAsRow extends React.Component {
  constructor (props) {
    super(props)
  }

  render () {
  	const { student } = this.props
    return (
      <div className='lead'>
        <h2>{student.name}</h2>-{student.reg_no}-{student.cgpa}-{student.section}
      </div>
    )
  }
}

export default StudentAsRow
