<template>
    <v-app id="inspire">


        <v-app-bar app
                   clipped-left>
       
            <v-toolbar-title class="green--text">NoteTaker</v-toolbar-title>
        </v-app-bar>

        <v-content>
 
            <div class="" style="width: 500px; margin: auto;">
                <div>
                    <v-tabs color="green" v-model="tab" vertical>
                        <v-tab v-for="item in items" :key="item.tab">
                            {{item.tab}}
                        </v-tab>
                        <v-tabs-items v-model="tab">
                                <v-card flat style="justify-content: center">
                                    <v-tab-item v-for="item in items" :key="item.tab">
                                            <v-textarea :placeholder="item.content" v-model="name"/>
                                    </v-tab-item>
                                </v-card>
                        </v-tabs-items>
                    </v-tabs>
                    <div class="selectWrap">
                        <v-btn class="btn" color="green" small dark @click="makeReq">
                            Submit
                        </v-btn>
                    </div>
                </div>
                {{output}}
            </div>

        </v-content>

        <v-footer app>
            <span>&copy; 2019 - Layout Components from Vuetify</span>
        </v-footer>
    </v-app>
</template>

<script>



    export default {
        props: {
            source: String,
        },
        data: () => ({
            drawer: null,
            tab: null,
            name: null,
            id: null,
            item_id: null,
            output: null,

            items: [
                { tab: 'INSERT', content: 'Insert a name for the field' },
                { tab: 'GET', content: 'Insert a name for the field' },
                { tab: 'DELETE', content: 'Insert a name for the field' },
                { tab: 'UPDATE', content: 'Insert a name for the field'},
            ],
         }),
        methods: {
            makeReq: function () {
                const url = 'https://5261puzqsb.execute-api.us-west-2.amazonaws.com/default';
                //const key = 'szqaVuropf37NRM8CgdhH3ekEynhYaEewYYz36Qb';

                let reqdata = {
                    "action": this.tab,
                    "name": this.name
                };

                const params = {
                    method: "POST",
                    body: JSON.stringify(reqdata)
                };
             
                fetch(url, params)
                    .then(data => {
                        return data.json();
                    })
                    .then(res => {
                        this.output = res;
                    })

                    .catch(error => this.output = error)
            }
        }
    }
</script>

<style scoped>
    .selectWrap {
        display: flex;
        justify-content: center;     
        margin: auto;
    }
    .btn {
        margin: 10px;
    }
</style>