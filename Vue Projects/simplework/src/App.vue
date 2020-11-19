<template>
  <div id="main">
    <header>
    <span class="title"><h1>SimpleWork</h1></span>
    </header>
    <div id="app">
      <Timer />
      <TaskContainer />
    </div>
  </div>
</template>

<script>
import TaskContainer from './components/TaskContainer.vue'
import Timer from './components/Timer.vue'

export default {
  name: 'App',
  components: {
    TaskContainer,
    Timer
  }
}
</script>

<style>
  
  #main {
    display: flex;
    flex-flow: column wrap;
    text-align: center;
    font-family: 'Roboto', Avenir, Helvetica, Arial, sans-serif;
    font-weight: bold;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
    max-width: 800px;
    
  }
  
  header {
    color: whitesmoke;
    border: 1px solid black;
    background-image: linear-gradient(to right, lightgreen, black);
  }
  
  .title {
    font-size: 15px;
  }

  #app {
    text-align: left;
    color: #2c3e50;
    padding-top: 30px;
    display: flex;
    flex-flow: row wrap;
    /* align-items: center; */
    border: 1px solid black
  }

</style>
