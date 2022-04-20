from django import forms

class TestForm(forms.Form):
    input1 = forms.CharField(label = 'First Input')
    input2 = forms.DecimalField(label = 'Second Input')