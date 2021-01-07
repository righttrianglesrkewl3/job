import dash
import dash_core_components as dcc
import dash_html_components as html
import plotly.graph_objs as go
from dash.dependencies import Input, Output
import dash_table
import datetime as dt
import pandas as pd
import numpy as np
import gridfs
import math
from io import StringIO
import os
import io

##########################################################
def get_clean_data(filename):
    clean_df = pd.read_csv(filename)
    clean_df['Date'] = pd.to_datetime(clean_df['Date'])
    del clean_df['Unnamed: 0']
    clean_df.index = clean_df['Date']
    del clean_df['Date']

    return clean_df

df = get_clean_data('small_sp500.csv')
#########################################################
app = dash.Dash()

app.layout = html.Div([
    dcc.Input(id='my-id-input', value='NWS', type='text'),
    #html.Div(id='my-div-output')])
    html.Div(id='basic-graph-container'),
    html.H4(children='Stock Data'),
    html.Div(id='table-container')
    ])

@app.callback(
    Output(component_id='basic-graph-container', component_property='children'),
    [Input(component_id='my-id-input', component_property='value')]
)
def update_output_div(input_value):
    dff = df[df['Stock'] == input_value]['Adj Close']

    return dcc.Graph(
        figure={
            'data': [
                {'x': dff.index, 'y': dff.values, 'type': 'line'},
            ],
            'layout': {
                'title': input_value }
        })


@app.callback(
    Output(component_id='table-container', component_property='children'),
    [Input(component_id='my-id-input', component_property='value')]
)
def generate_table(selected_stock):
    dff = df.copy()
    dff = df[df['Stock'] == selected_stock]
    dff.reset_index(inplace=True)
    #print(dff.head()) # debug
    dff = dff.round(2)

    return dash_table.DataTable(
    data=dff.to_dict('records'),
    columns=[{'id': c, 'name': c} for c in dff.columns],
    style_table={
            'maxHeight': '300px',
            'overflowY': 'scroll'
        },
    style_cell_conditional=[
        {'if': {'column_id': 'Industry'},
         'width': '30%'},
    ]
)

if __name__ == '__main__':
    app.run_server()
