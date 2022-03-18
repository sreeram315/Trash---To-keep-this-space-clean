import React, { Component } from 'react'

import Dropzone from 'react-dropzone'
import ReactCrop from 'react-image-crop'
import 'react-image-crop/dist/ReactCrop.css'

import {downloadBase64File, image64toCanvasRef, extractImageFileExtensionFromBase64, base64StringtoFile} from './utils'


const parentStyle = {
  width: 200,
  height: 200,
  border: '2px dashed #888'
}

const imgStyle = {
	margin: 20,
  width: 1100,
  height: 590,
  border: '2px dashed #888'
}

class TesterApp3 extends Component {
	constructor(props){
		super(props)
		this.croppedImagePreviewRef = React.createRef()
		this.state = {
			imgSrc: '',
			crop: {
			  aspect: 1/1
			}
		}
	}

  handleFileDrop = (files, rejectedFiles) => {
  	const file = files[0]
  	const reader = new FileReader()
  	
  	reader.addEventListener("load", ()=>{
  		const imgresult = reader.result
  		this.setState({
  		imgSrc: imgresult
  	})
  	}, false)
  	reader.readAsDataURL(file)
  }

  handelImageOnChange = (crop) => {
  	this.setState({crop:crop})
  }
  handelImageOnCrop = (crop) => {
  	// console.log(crop)
  }
  handleCropOnComplete = (crop, pixelCrop) => {
  	console.log(pixelCrop)
  	const canvRef = this.croppedImagePreviewRef.current
  	image64toCanvasRef(canvRef , this.state.imgSrc , pixelCrop)

  }

  downloadImage = (event) => {
  	event.preventDefault()
  	const canvRef = this.croppedImagePreviewRef.current
  	const {imgSrc} = this.state
  	const fileExtension = extractImageFileExtensionFromBase64(imgSrc)

  	const image64 = canvRef.toDataURL('image/' + fileExtension)
  	const downFilename = "somefile" + fileExtension
  	downloadBase64File(image64,  downFilename)

  	// for making file
  	const fileName = base64StringtoFile(image64, downFilename )
  	console.log(fileName)
  }






   render() {
   	const {imgSrc} = this.state
   	const {te} = this.state
    return (
    <div>
    	{imgSrc.length !== 0 
    		? 
    			<div>
    				<ReactCrop
    					src={imgSrc}
    					crop={this.state.crop}
    					onChange={this.handelImageOnChange}
    					onComplete={this.handleCropOnComplete}
    				/><br/><br/>

    				<canvas ref={this.croppedImagePreviewRef}></canvas><br/>
    				<button onClick={this.downloadImage}> Download image</button>
    			</div>
    			
    		:
		      <Dropzone onDrop={this.handleFileDrop} accept='image/*' multiple={true} onFocus={this.handleOnDragEnter} preventDropOnDocument={false}>
		        {({getRootProps, getInputProps, isDragActive, isFocused}) => {
		          return (
		            <div {...getRootProps()}>
		              <input {...getInputProps()} />
		              {
		                  <p>Drop some files here, or click to select files to upload.</p>
		              }
		            </div>
		          )
		        }}
		      </Dropzone>
  		}
  		
    </div>

    )
  }




}



export default TesterApp3
