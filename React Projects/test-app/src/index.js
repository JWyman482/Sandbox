import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import * as serviceWorker from './serviceWorker';

function Johntest(props) {
  return <h1>This is JOHNTEST! {props.tester}</h1>
}

// class Johntest2 extends React.Component {
//   constructor(props) {
//     super(props)
//   }
// }

ReactDOM.render(
  <React.StrictMode>
    <App />
    <Johntest tester="Made It!"/>
  </React.StrictMode>,
  document.getElementById('root')
);

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: https://bit.ly/CRA-PWA
serviceWorker.unregister();
