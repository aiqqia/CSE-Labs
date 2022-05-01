from django.db import models
from django.core.validators import MinValueValidator
from django import forms

# Create your models here.
class Product(models.Model):
    id = models.AutoField(primary_key=True)
    title = models.CharField(max_length = 50)
    body = models.CharField(max_length = 200)
    price = models.IntegerField(validators = [MinValueValidator(0)])
    timestamp = models.DateTimeField()
    class Meta:
        ordering = ('-timestamp',)
    
class ProductForm(forms.ModelForm):
    class Meta:
        exclude = ('timestamp',)
        model = Product

class Option(models.Model):
    id = models.AutoField(primary_key=True)
    value = models.CharField(max_length=100)
    number = models.IntegerField()

class Question(models.Model):
    id = models.AutoField(primary_key=True)
    question = models.CharField(max_length=100)
    options = models.ManyToManyField(Option)
