<template>
  <div id="app">
    <TaskContainer />
  </div>
</template>

<script>
import TaskContainer from './components/TaskContainer.vue'

export default {
  name: 'App',
  components: {
    TaskContainer
  }
}
</script>

<style>
#app {
  font-family: 'Open Sans', Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
