<template>
    <v-app id="inspire">

        <v-app-bar app clipped-left>
            <v-toolbar-title class="green--text">NoteTaker</v-toolbar-title>
        </v-app-bar>

        <v-content>
 
            <div class="" style="width: 500px; margin: auto;">
                <div>
                    <span>Click a selection below</span>
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
                {{output}}
                </div>
                <table>
                    <tr class="tbl">
                        <th>ID</th><th>Name</th>
                    </tr>
                    <tr class="tbl" v-for="(rows, index) in output" :key="index">
                        <td>{{rows.item_id}}</td>
                        <td class="names">{{rows.name}}</td>
                    </tr>
                </table>
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

            tab: null,
            name: null,
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

                var reqdata = {
                    "action": ""
                };

                reqdata["action"] = this.items[this.tab].tab.toLowerCase();
                // reqdata["name"] = this.name;
                // reqdata["id"] = this.itemid;

                console.log(reqdata);

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
    .tbl {
        text-align: center;
        margin: auto;
        padding: 10px;
        /* border: 5px soild red; */
    }
    .tbl th, .tbl td {
        padding: 10px 20px;
    }
    .names {
        text-align: left;
    }
</style>