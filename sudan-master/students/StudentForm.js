import React, { Component } from 'react'
import Dropzone from 'react-dropzone'


class InputBlock extends Component{
  constructor(props){
    super(props)
    this.textInput = null
    this.setInpuRef = element => {
      this.textInput = element
    }
  }

  handleOnChange = (event) => {
    if (this.props.onChange) this.props.onChange(event)
  }

  componentDidMount(){
    this.textInput.focus()
  }

  render(){
    return(
      <div>
        <p><input ref={this.setInpuRef} name={this.props.myName} value={this.props.myValue} placeholder = {this.props.myPlaceholder} onChange={this.handleOnChange} /></p>
      </div>
      )
  }
}

class StudentForm extends Component {
  constructor (props) {
    super(props)
    this.state = {
      fullName: '',
      value: ""
    }
  }

  handleNameChange = (event) => {
    event.preventDefault()
    this.setState({
      [event.target.name]: event.target.value,
      value: event.target.value
    })
  }

  clearNameField = (event) => { 
    event.preventDefault()
    console.log(event.target.name)
    
  }


  focusOnName = (event) => {
    event.preventDefault()
    this.inputFullNameRef.focus()
  }

  handleFormSubmit = (event) => {
    event.preventDefault()
    console.log(this.state)
  }

  handleOnDrop = (acceptedFiles, rejectedFiles) => {
      console.log(acceptedFiles)
      console.log(rejectedFiles)
   }

  componentDidMount () {
    // this.inputFullNameRef.current.focus()
  }

  render () {
    const { fullName } = this.state
    return (
      <div>
        <h1>Full name is: {fullName}</h1>
        <form method='POST' onSubmit={this.handleFormSubmit}>
        <InputBlock myName="fullName" myPlaceholder="Full Name" myValue={this.state.value} onChange={this.handleNameChange}></InputBlock>
          <button onClick={this.focusOnName}>Focus on Name</button>&ensp;
          <button onClick={this.clearNameField}>Clear name field</button>&ensp;
          <button>Save</button>
        </form>


     <Dropzone onDrop={this.handleOnDrop}>
      {({getRootProps}) => (

          <div {...getRootProps()}>
          
            <p>Drop files here, or click to select files</p>
          </div>
      )}
    </Dropzone>


      </div>

    )
  }
}

export default StudentForm


          // <p><input ref={node => this.inputFullNameRef = node} type='text' placeholder='Full Name' name='fullName' onChange={this.handleNameChange} /></p>

