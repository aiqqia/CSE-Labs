from django import forms

subjects = [('Maths', 'Maths'), ('Science', 'Science'), ('English', 'English'), ('Hindi', 'Hindi')]

class FirstForm(forms.Form):
    name= forms.CharField()
    roll = forms.CharField()
    subject = forms.ChoiceField(widget=forms.Select, choices=subjects)

