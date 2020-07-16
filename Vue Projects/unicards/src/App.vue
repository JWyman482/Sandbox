<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/logo.png" />
    <HelloWorld msg="Welcome to Your Vue.js App" />
  </div>
</template>

<script>
import HelloWorld from "./components/HelloWorld.vue";
// TO DO: make a card object with
//  Unicorns
//  Upgrades
//  Downgrades
//  Magics
//  Instants*
//
// TO DO: make a player object with
// Stable
//  Cards
// Hand
//  Cards
//  Visible/invisible flag

// TO DO: make a deck object with
//  Cards

// TO DO: make a game object with
//  Players
//  Deck
//  CurrentPlayer

export default {
  name: "App",
  components: {
    HelloWorld
  },
  // ADDED THIS SECTION
  data: function() {
    return {
      currentPlayer: 0,
      
    }
  }
  // END ADDED SECTION
};
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
