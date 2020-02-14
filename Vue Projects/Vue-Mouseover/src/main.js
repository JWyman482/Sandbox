import Vue from 'vue';
import App from './App.vue';
import vuetify from 'vuetify';
import '@babel/polyfill'
import 'roboto-fontface/css/roboto/roboto-fontface.css'
import '@mdi/font/css/materialdesignicons.css'

Vue.config.productionTip = true;

new Vue({
    vuetify,
    render: h => h(App)
}).$mount('#app');
