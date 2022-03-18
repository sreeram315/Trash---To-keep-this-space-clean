import React, { Component } from 'react'
// // import logo from './logo.svg'
// import './App.css'
// import StudentList from './students/StudentList.js'

// import TesterData from '../data/tester_data.json'

function AlertBox (props) {
  return <div className={'alert ' + props.class_name}><h1> {props.children} </h1></div>
}

export default AlertBox

export function downloadBase64File (base64Data, filename) {
  var element = document.createElement('a')
  element.setAttribute('href', base64Data)
  element.setAttribute('download', filename)
  element.style.display = 'none'
  document.body.appendChild(element)
  element.click()
  document.body.removeChild(element)
}

export function base64StringtoFile (base64String, filename) {
  var arr = base64String.split(','); var mime = arr[0].match(/:(.*?);/)[1]

  var bstr = atob(arr[1]); var n = bstr.length; var u8arr = new Uint8Array(n)
  while (n--) {
    u8arr[n] = bstr.charCodeAt(n)
  }
  return new File([u8arr], filename, { type: mime })
}

export function extractImageFileExtensionFromBase64 (base64Data) {
  return base64Data.substring('data:image/'.length, base64Data.indexOf(';base64'))
}

export function image64toCanvasRef (canvasRef, image64, pixelCrop) {
  const canvas = canvasRef // document.createElement('canvas');
  canvas.width = pixelCrop.width
  canvas.height = pixelCrop.height
  const ctx = canvas.getContext('2d')
  const image = new Image()
  image.src = image64
  image.onload = function () {
    ctx.drawImage(
      image,
      pixelCrop.x,
      pixelCrop.y,
      pixelCrop.width,
      pixelCrop.height,
      0,
      0,
      pixelCrop.width,
      pixelCrop.height
    )
  }
}
