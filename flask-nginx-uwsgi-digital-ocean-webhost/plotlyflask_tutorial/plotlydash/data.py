"""Prepare data for Plotly Dash."""
import numpy as np
import pandas as pd


def create_dataframe():
    """Create Pandas DataFrame from local CSV."""
    df = pd.read_csv("data/hockey_data.csv", parse_dates=["seasons"])
    df.drop(columns=["time_type"], inplace=True)
    return df

