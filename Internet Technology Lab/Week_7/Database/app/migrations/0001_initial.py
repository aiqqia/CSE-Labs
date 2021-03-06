# Generated by Django 2.2.28 on 2022-04-25 09:34

import django.core.validators
from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Product',
            fields=[
                ('id', models.AutoField(primary_key=True, serialize=False)),
                ('title', models.CharField(max_length=50)),
                ('body', models.CharField(max_length=200)),
                ('price', models.IntegerField(validators=[django.core.validators.MinValueValidator(0)])),
                ('timestamp', models.DateTimeField()),
            ],
            options={
                'ordering': ('-timestamp',),
            },
        ),
    ]
